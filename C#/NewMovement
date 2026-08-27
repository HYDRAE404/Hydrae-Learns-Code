using System.Collections;
using System.Runtime.CompilerServices;
using Unity.VisualScripting;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [Header("Setup")]
    [SerializeField] private LayerMask groundLayer;
    [SerializeField] private LayerMask RunnableWall;
    [SerializeField] private Rigidbody rb;
    public Transform orientation;

    [Header("Movement Settings")]
    [SerializeField] private float defaultSpeed;
    public float sprintMultiplier;
    [SerializeField] private float groundDrag;
    [SerializeField] private float maxSlopeAngle;

    private float moveSpeed;
    private float currentMoveSpeed;
    private float previousSpeed;

    [Header("Jump Settings")]
    [SerializeField] private float jumpForce;
    [SerializeField] private float jumpCooldown;
    [SerializeField] private float airMultiplier;
    private bool readyToJump;

    [Header("Slide Settings")]
    [SerializeField] private float slideSpeedMultiplier;
    [SerializeField] private float slideForce;
    [SerializeField] private float slideDrag;
    [SerializeField] private float maxSlideTime;
    [SerializeField] private float speedIncMultiplier;
    [SerializeField] private float slopeIncMultiplier;
    RaycastHit slopeHit;
    private float slideTimer;
    private Vector3 playerScale;
    private Vector3 slideScale = new Vector3(1, 0.5f, 1);

    [Header("WallRun Settings")]
    [SerializeField] private float wallRunSpeeedMultiplier;
    [SerializeField] private float wallRunForce;
    [SerializeField] private float wallJumpUpForce;
    [SerializeField] private float wallJumpSideForce;
    [SerializeField] private float wallCheckDistance;
    [SerializeField] private float minJumpHeight;
    [SerializeField] private float exitWallTime;
    private RaycastHit leftWallHit;
    private RaycastHit rightWallHit;
    [HideInInspector] public bool wallLeft;
    [HideInInspector] public bool wallRight;
    private bool exitingWall;
    private float exitWallTimer;

    // others
    private float horizontalInput;
    private float verticalInput;
    [HideInInspector] public Vector3 move;

    // movements bools
    public bool isSprinting;
    public bool isGrounded;
    public bool isJumping;
    public bool exitSlope;
    public bool isSliding;
    public bool isWallRunning;

    [Header("DEBUG TOOLS (REMOVE LATER)")]
    private bool isSlope;
    private float rbMag;
    private bool rbMagSufficient;
    private float angleDetect;

    void Start()
    {
        moveSpeed = defaultSpeed;
        readyToJump = true;
        playerScale = transform.localScale;
    }

    void Update()
    {
        // DEBUG TOOLS (REMOVE LATER)
        rbMag = rb.linearVelocity.magnitude;
        isSlope = OnSlope();
        angleDetect = Vector3.Angle(Vector3.up, slopeHit.normal);
        // --------------------------

        StateHandle();
        Drag();
        WallCheck();
    }

    private void FixedUpdate()
    {
        Move();
        SpeedCtrl();

        if (isSliding)
        {
            Sliding();
        }
        if (isWallRunning)
        {
            WallRunning();
        }
    }

    #region HANDLERS
    // Handles inputs and states
    void StateHandle()
    {
        horizontalInput = Input.GetAxisRaw("Horizontal");
        verticalInput = Input.GetAxisRaw("Vertical");
        isGrounded = Physics.Raycast(transform.position, Vector3.down, 1.2f, groundLayer);
        isJumping = Input.GetKey(KeyCode.Space);
        isSprinting = Input.GetKey(KeyCode.LeftShift);

        currentMoveSpeed = isSprinting ? defaultSpeed * sprintMultiplier : defaultSpeed;

        // slide speed
        if (isSliding)
        {
            if (OnSlope() && rb.linearVelocity.y < 0.1f) currentMoveSpeed = defaultSpeed * slideSpeedMultiplier;
            else currentMoveSpeed = defaultSpeed * sprintMultiplier;
        }

        // check if speed change is drastic
        if (Mathf.Abs(previousSpeed - currentMoveSpeed) > (defaultSpeed*sprintMultiplier-defaultSpeed) && moveSpeed != 0)
        {
            StopAllCoroutines();

            Vector3 horizontalVel = new Vector3(rb.linearVelocity.x, 0f, rb.linearVelocity.z);
            if (horizontalVel.magnitude > currentMoveSpeed)
                moveSpeed = horizontalVel.magnitude;

            StartCoroutine(SmoothSpeedChange());
        }
        else
        {
            moveSpeed = currentMoveSpeed;
        }

        previousSpeed = currentMoveSpeed;

        // jump check
        if (isGrounded && isJumping && readyToJump)
        {
            readyToJump = false;

            Jump();

            Invoke(nameof(ResetJump), jumpCooldown);
        }

        // slide check
        if (Input.GetKeyDown(KeyCode.LeftControl) && (horizontalInput != 0 || verticalInput != 0))
        {
            StartSlide();
        }
        if (Input.GetKeyUp(KeyCode.LeftControl) && isSliding)
        {
            StopSlide();
        }

        // wall run check
        if (isWallRunning) currentMoveSpeed *= wallRunSpeeedMultiplier;

        if ((wallLeft || wallRight) && verticalInput > 0 && AboveGround() && !exitingWall)
        {
            if (!isWallRunning) StartWallRun();

            // wall jump
            if (isJumping) WallJump();
        }
        else if (exitingWall)
        {
            if (isWallRunning) StopWallRun();
            if (exitWallTimer > 0) exitWallTimer -= Time.deltaTime;
            if (exitWallTimer <= 0) exitingWall = false;
        }
        else
        {
            if (isWallRunning) StopWallRun();
        }
    }

    // smoothly change from previous speed to another
    private IEnumerator SmoothSpeedChange()
    {
        float time = 0;
        float difference = Mathf.Abs(currentMoveSpeed - moveSpeed);
        float startValue = moveSpeed;

        while (time < difference)
        {
            moveSpeed = Mathf.Lerp(startValue, currentMoveSpeed, time / difference);

            if (OnSlope())
            {
                float slopeAngle = Vector3.Angle(Vector3.up, slopeHit.normal);
                float slopeAngleInc = 1 + (slopeAngle / 90f);

                time += Time.deltaTime * speedIncMultiplier * slopeIncMultiplier * slopeAngleInc;
            }
            else
                time += Time.deltaTime * speedIncMultiplier;

            yield return null;
        }

        moveSpeed = currentMoveSpeed;
    }

    #endregion

    #region MOVEMENT
    // Movement
    void Move()
    {
        move = orientation.forward * verticalInput + orientation.right * horizontalInput;

        if (!isWallRunning) rb.useGravity = !OnSlope();

        if (OnSlope() && !exitSlope)
        {
            rb.AddForce(SlopeDirection(move) * moveSpeed * 10f, ForceMode.Force);

            if (rb.linearVelocity.y > 0)
            {
                rb.AddForce(Vector3.down * 80f, ForceMode.Force);
            }
        }
        else if (isGrounded)
        {
            rb.AddForce(move.normalized * moveSpeed * 10f, ForceMode.Force);
        }
        else if (!isGrounded)
        {
            rb.AddForce(move.normalized * moveSpeed * 10f * airMultiplier, ForceMode.Force);
        }
    }

    // Drag Handling
    void Drag()
    {
        if (isGrounded)
        {
            if (isSliding) rb.linearDamping = slideDrag;
            else rb.linearDamping = groundDrag;
        }
        else rb.linearDamping = 0;
    }

    // Speed Control
    void SpeedCtrl()
    {
        // limit speed on slope
        if (OnSlope() && !exitSlope)
        {
            if (rb.linearVelocity.magnitude > moveSpeed)
            {
                rb.linearVelocity = rb.linearVelocity.normalized * moveSpeed;
            }
        }
        else
        {
            // Calculate current horizontal velocity
            Vector3 rbVel = new Vector3(rb.linearVelocity.x, 0f, rb.linearVelocity.z);

            // Limit velocity if it goes above currentMoveSpeed
            if (rbVel.magnitude > moveSpeed)
            {
                Vector3 limitedVel = rbVel.normalized * moveSpeed;
                rb.linearVelocity = new Vector3(limitedVel.x, rb.linearVelocity.y, limitedVel.z);
            }
        }
    }
    #endregion

    #region JUMPING
    void Jump()
    {
        rb.linearVelocity = new Vector3(rb.linearVelocity.x, 0f, rb.linearVelocity.z);

        rb.AddForce(transform.up * jumpForce, ForceMode.Impulse);
    }

    void ResetJump()
    {
        readyToJump = true;

        exitSlope = false;
    }
    #endregion

    #region SLIDING
    void StartSlide()
    {
        isSliding = true;

        transform.localScale = slideScale;
        rb.AddForce(Vector3.down * 5f, ForceMode.Impulse);

        slideTimer = maxSlideTime;
    }

    void StopSlide()
    {
        isSliding = false;

        transform.localScale = playerScale;
    }

    void Sliding()
    {
        Vector3 inputDirection = orientation.forward * verticalInput +
            orientation.right * horizontalInput;

        // sliding normal
        if (!OnSlope() || rb.linearVelocity.y > -0.1f)
        {
            rb.AddForce(inputDirection.normalized * slideForce, ForceMode.Force);

            slideTimer -= Time.deltaTime;
        }
        // sliding on slope
        else
        {
            rb.AddForce(SlopeDirection(inputDirection) * slideForce, ForceMode.Force);
        }

        if (slideTimer <= 0) StopSlide();
    }

    // slope handler
    bool OnSlope()
    {
        if (Physics.Raycast(transform.position, Vector3.down, out slopeHit, 1.3f))
        {
            float angle = Vector3.Angle(Vector3.up, slopeHit.normal);
            return angle <= maxSlopeAngle && angle != 0;
        }
        return false;
    }

    Vector3 SlopeDirection(Vector3 direction)
    {
        return Vector3.ProjectOnPlane(direction, slopeHit.normal).normalized;
    }
    #endregion

    #region WALL RUNNING
    void StartWallRun()
    {
        isWallRunning = true;

        rb.linearVelocity = new Vector3(
            rb.linearVelocity.x,
            0f,
            rb.linearVelocity.z
            );
    }

    void WallRunning()
    {

        Vector3 wallNormal = wallRight ? rightWallHit.normal : leftWallHit.normal;
        Vector3 wallForward = Vector3.Cross(wallNormal, transform.up);

        if ((orientation.forward - wallForward).magnitude > (orientation.forward + wallForward).magnitude)
            wallForward = -wallForward;

        // forward force
        rb.AddForce(wallForward * wallRunForce, ForceMode.Force);

        // push to wall
        if (!(wallLeft && horizontalInput > 0) && !(wallRight && horizontalInput < 0))
            rb.AddForce(-wallNormal * 100, ForceMode.Force);
    }

    void StopWallRun()
    {
        isWallRunning = false;
    }

    void WallJump()
    {
        // exit wall state
        exitingWall = true;
        exitWallTimer = exitWallTime;

        Vector3 wallNormal = wallRight ? rightWallHit.normal : leftWallHit.normal;

        Vector3 forceToApply = transform.up * wallJumpUpForce + wallNormal * wallJumpSideForce;

        // add force
        rb.linearVelocity = new Vector3(
            rb.linearVelocity.x,
            0f,
            rb.linearVelocity.z
            );
        rb.AddForce(forceToApply, ForceMode.Impulse);
    }

    void WallCheck()
    {
        wallRight = Physics.Raycast(transform.position, orientation.right, out rightWallHit, wallCheckDistance, RunnableWall);
        wallLeft = Physics.Raycast(transform.position, -orientation.right, out leftWallHit, wallCheckDistance, RunnableWall);
    }

    bool AboveGround()
    {
        return !Physics.Raycast(transform.position, Vector3.down, minJumpHeight, groundLayer);
    }

    #endregion
}